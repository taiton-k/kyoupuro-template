#pragma once



#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/bipartite.hpp>



namespace taiton {


template<class ifDirected,class EdgeProperty = boost::no_property>
using graph_t_impl = boost::adjacency_list<boost::vecS,boost::vecS,ifDirected,boost::no_property,EdgeProperty>;

using directed_graph_t = graph_t_impl<boost::directedS>;
using undirected_graph_t = graph_t_impl<boost::undirectedS>;

template<class Graph>
using vertex_t = typename Graph::vertex_descriptor;

template<class Graph>
using edge_t = typename Graph::edge_descriptor;


template<class Graph>
void get_distance(const Graph& g,std::vector<int>& dist,typename Graph::vertex_descriptor s = 0){
        boost::breadth_first_search(g,s,boost::visitor(boost::make_bfs_visitor(boost::record_distances(dist.data(),boost::on_tree_edge{}))));
}


}
