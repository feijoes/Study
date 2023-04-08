package feijoes.study.learningjpa.interfaces.services

import java.util.*

interface ModelService<T>{
    fun findAll(): List<T>

    fun save(model: T): T
    fun findById(id: Long): Optional<T>
    fun deleteById(id: Long)
}
