package feijoes.study.learningjpa.models

import jakarta.persistence.Entity
import jakarta.persistence.GeneratedValue
import jakarta.persistence.Id


@Entity
data class User (@Id @GeneratedValue val id:Long,val name:String)