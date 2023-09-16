fun main() {
    
    val universe = mutableSetOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    val subsets = listOf(
        setOf(1, 2, 3, 4, 5),
        setOf(4, 5, 6, 7),
        setOf(8, 9, 10),
        setOf(2, 5, 7)
    )

    val solution = getCoveringByGreedy(universe, subsets)

    println("Selected subsets indices: $solution")

}

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

