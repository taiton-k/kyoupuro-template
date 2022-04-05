#pragma once

#include <boost/geometry.hpp>
#if BOOST_VERSION < 107800
#include <boost/geometry/algorithms/detail/azimuth.hpp>
#endif //BOOST_VERSION < 107800



namespace taiton{


#if BOOST_VERSION < 107800
template<class Point1,class Point2>
inline long double azimuth(const Point1 &p1,const Point2 &p2){
        return azimuth<long double>(p1,p2);
}

template<typename T>
class point3_t : public boost::geometry::model::point<T,3,boost::geometry::cs::cartesian> {
        using Base = boost::geometry::model::point<T,3,boost::geometry::cs::cartesian>;
public:
        using Base::Base;

        constexpr inline T x() noexcept {
                return this->template get<0>();
        }

        constexpr inline T y() noexcept {
                return this->template get<1>();
        }

        constexpr inline T z() noexcept {
                return this->template get<2>();
        }
};

#else //BOOST_VERSION < 107800

template<typename T>
using point3_t = boost::geometry::model::d3::point_xyz<T>;

#endif //BOOST_VERSION < 107800


template<typename T>
using point2_t = boost::geometry::model::d2::point_xy<T>;

template<class Point>
using segment_t = boost::geometry::model::segment<Point>;

template<class Point>
inline Point rotate(Point geo,double deg){
        boost::geometry::transform(geo,geo,boost::geometry::strategy::transform::rotate_transformer<boost::geometry::degree,long double,2,2>{deg});
        return geo;
}

template<class Point>
inline Point rotate(Point geo,const Point& org,double deg){
        geo.template set<0>(geo.template get<0>() - org.template get<0>());
        geo.template set<1>(geo.template get<1>() - org.template get<1>());

        geo = rotate(geo,deg);

        geo.template set<0>(geo.template get<0>() + org.template get<0>());
        geo.template set<1>(geo.template get<1>() + org.template get<1>());

        return geo;
}


} // namespace taiton
