import java.util.PriorityQueue

data class Edge(val destination: Int, val weight: Int)


data class Graph(private val numberOfNodes: Int) {
    private val neighborsNodes: MutableList<MutableList<Edge>> =
        MutableList(numberOfNodes) { mutableListOf() }

    fun addEdge(source: Int, destination: Int, weight: Int) {
        neighborsNodes[source].add(Edge(destination, weight))
        //  neighborsNodes[destination].add(Edge(source, weight)) // For undirected graph
    }

    fun findShortestPaths(sourceNode: Int) {
        val shortestDistances = IntArray(numberOfNodes) { Int.MAX_VALUE }
        shortestDistances[0] = 0

        val minHeap = PriorityQueue<Edge>(compareBy { it.weight })
        minHeap.add(Edge(sourceNode, 0))

        val visited = mutableSetOf<Int>() // Set to track visited nodes

        while (minHeap.isNotEmpty()) {
            val currentEdge = minHeap.poll()
            val currentNode = currentEdge.destination

            // Skip processing if the node is already visited
            if (currentNode in visited) {
                continue
            }
            visited.add(currentNode) // Mark the current node as visited

            for (edge in neighborsNodes[currentNode]) {
                val neighborNode = edge.destination
                val edgeWeight = edge.weight

                if (shortestDistances[currentNode] != Int.MAX_VALUE &&
                    shortestDistances[currentNode] + edgeWeight < shortestDistances[neighborNode]
                ) {
                    shortestDistances[neighborNode] = shortestDistances[currentNode] + edgeWeight
                    minHeap.add(Edge(neighborNode, shortestDistances[neighborNode]))
                }
            }
        }

        // Print the shortest distances from the source vertex
        for (i in 0 until numberOfNodes) {
            println("Shortest distance from node $sourceNode to node $i is ${shortestDistances[i]}")
        }
    }
}

fun main() {
    val graph = Graph(6)

    graph.addEdge(0, 1, 4)
    graph.addEdge(0, 2, 3)
    graph.addEdge(1, 2, 1)
    graph.addEdge(1, 3, 2)
    graph.addEdge(2, 3, 4)
    graph.addEdge(3, 4, 2)
    graph.addEdge(4, 5, 6)

    println(graph.findShortestPaths(0))
}
