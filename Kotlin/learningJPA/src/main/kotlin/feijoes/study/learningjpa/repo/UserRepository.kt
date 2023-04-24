package feijoes.study.learningjpa.repo


import feijoes.study.learningjpa.models.User
import org.springframework.data.jpa.repository.JpaRepository


interface UserRepository : JpaRepository<User, Long?>