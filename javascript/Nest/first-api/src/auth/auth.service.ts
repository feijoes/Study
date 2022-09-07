import { Injectable } from '@nestjs/common'
import { PrismaService } from '../prisma/prisma.service'
import { AuthDto } from './dto'
import { createUser } from './functions/CreateUser'

@Injectable({})
export class AuthService {
  constructor(private prisma: PrismaService) {}
  sigup(dto :AuthDto) {
    
    return createUser(dto,this.prisma)
  }

  sigin() {
    return { msg: 'You have signed in' }
  }
}
