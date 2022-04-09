#pragma once



#include <boost/graph/directed_graph.hpp>
#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/bipartite.hpp>



namespace taiton {


template<class Graph>
using vertex_t = typename boost::graph_traits<Graph>::vertex_descriptor;

template<class Graph>
using edge_t = typename boost::graph_traits<Graph>::edge_descriptor;


template<class Graph>
void get_distance(const Graph& g,std::vector<int>& dist,typename Graph::vertex_descriptor s = 0){
        boost::breadth_first_search(g,s,boost::visitor(boost::make_bfs_visitor(boost::record_distances(dist.data(),boost::on_tree_edge{}))));
}


}
