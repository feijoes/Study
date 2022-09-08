import { Injectable } from '@nestjs/common'
import { PrismaService } from '../prisma/prisma.service'
import { AuthDto } from './dto'
import { createUser } from './functions/CreateUser'
import { findUser } from './functions/FindUser'
@Injectable({})
export class AuthService {
  constructor(private prisma: PrismaService) {}
  sigup(dto: AuthDto) {
    return createUser(dto, this.prisma)
  }

  sigin(dto: AuthDto) {
    return findUser(dto, this.prisma)
  }
}
