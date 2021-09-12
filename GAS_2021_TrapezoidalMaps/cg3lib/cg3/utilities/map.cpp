/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */

#include "map.h"
#include <algorithm>

namespace cg3 {

/**
 * @ingroup cg3core
 * @brief this function flips a std::map on a std::multimap. All the elements of the multimap will be sorted by the value of the map.
 * @param[in] src: input map
 * @return the flipped multimap
 */
template<typename A, typename B, template<class,class,class...> class M, class... Args>
inline std::multimap<B,A> flipMap(const M<A,B,Args...> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(),
                   std::inserter(dst, dst.begin()),
                   flipPair<A,B>);
    return dst;
}

/**
 * @ingroup cg3core
 * @brief contains
 * @param m
 * @param obj
 * @return
 */
template<typename K, typename V, typename ...A>
inline bool contains(const std::map<K, V, A...>& m, const K& obj)
{
	return m.find(obj) != m.end();
}

}
