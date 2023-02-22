fun main () {
val x: IntArray = intArrayOf(1, 5, 3,0)
    println(selectionSort(x).toList())
}

fun selectionSort(arr :IntArray):IntArray{
   var temp:Int
   var minIdx:Int
    for(i in 0 until arr.size){
        minIdx =arr[i]
        for (j in i+1 until arr.size){
            if(arr[j]<minIdx){
                minIdx =j
            }
        }
        temp= arr[minIdx]
        arr[minIdx]=arr[i]
        arr[i]=temp
    }
        
        return arr
}
