package feijoes.study.learningjpa.services

import feijoes.study.learningjpa.interfaces.services.ModelService

import feijoes.study.learningjpa.models.User
import org.springframework.jdbc.core.JdbcTemplate
import org.springframework.stereotype.Service
import java.util.*

@Service
class UserService(val db: JdbcTemplate) : ModelService<User> {
    override fun findAll(): List<User> {
        return listOf(User(12, "Pedro"))
        /*
        return db.query("select * from messages") { response, _ ->
            Message(
                response.getString("id"),
                response.getString("text"),
            )
        }
         */
    }

    override fun findById(id: Long): Optional<User> {
        TODO("Not yet implemented")
    }

    override fun deleteById(id: Long) {
        TODO("Not yet implemented")
    }

    fun test(msg: String) {
        println(msg)
    }

    override fun save(model: User): User {

         db.update(
            "insert into users values ( ?, ? )",
            model.id,
            model.name
        )
        return model
    }


}
