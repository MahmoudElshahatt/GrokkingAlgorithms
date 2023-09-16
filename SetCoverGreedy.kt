
fun getCoveringByGreedy(universe: MutableSet<Int>, subsets: List<Set<Int>>): List<Int>? {
    val solution: MutableList<Int> = ArrayList()
    var bestSubsetIndex = -1
    var bestSubsetSize = -1
    
    while (universe.isNotEmpty()) {
        for (i in subsets.indices) {
            val currentSubset = subsets[i]
            var intersectionSize = 0
            for (element in currentSubset) {
                if (universe.contains(element)) {
                    intersectionSize++
                }
            }
            if (intersectionSize > bestSubsetSize) {
                bestSubsetSize = intersectionSize
                bestSubsetIndex = i
            }
        }
        if (bestSubsetIndex != -1) {
            solution.add(bestSubsetIndex)
            for (element in subsets[bestSubsetIndex]) {
                universe.remove(element)
            }
        } else {
            break
        }
    }
    return solution
}

