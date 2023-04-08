package feijoes.study.learningjpa.controllers

import feijoes.study.learningjpa.models.User
import feijoes.study.learningjpa.services.UserService
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.*
import org.springframework.web.servlet.support.ServletUriComponentsBuilder

class UserController(private val userService: UserService) {

    @GetMapping("/")
    fun getAllUsers(): List<User> {
        return userService.findAll()
    }

    @GetMapping("/{id}")
    fun getUserById(@PathVariable id: Long): ResponseEntity<User> {
        val user = userService.findById(id)
        return if (user.isPresent) {
            ResponseEntity.ok(user.get())
        } else {
            ResponseEntity.notFound().build()
        }
    }

    @PostMapping("/")
    fun createUser(@RequestBody user: User): ResponseEntity<User> {
        val createdUser = userService.save(user)
        val location = ServletUriComponentsBuilder.fromCurrentRequest()
            .path("/{id}")
            .buildAndExpand(createdUser.id)
            .toUri()
        return ResponseEntity.created(location).body(createdUser)
    }

    @DeleteMapping("/{id}")
    fun deleteUser(@PathVariable id: Long): ResponseEntity<Void> {
        userService.deleteById(id)
        return ResponseEntity.noContent().build()
    }
}