

fun test():String = "Test function"

fun SayName(greeting:String?,name:String){
    println(greeting)
    println("Hello $name")
}
fun main(){
    /* declarin variables */
    /* Pode ser mudado */
    var variables: String = ""

    /* Inmutavel */
    val variable2: Int? = 1

    var name: String? = null

    if (name == null){
        println(" Name is null")
    } else {
        println("Name is not null")
    }
    when (variable2){
        1 -> println(1)
        null -> print("is null")
    }
    println(test())
    SayName(name="Pedro",greeting="HI")


    var array = listOf("Pedro",2,arrayOf(3,4,5))
    println(array[2])
    println(array[0])
    println(array.size)

    array.forEach { 
    println(it) 
}
} 
