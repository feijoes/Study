import { Injectable } from '@nestjs/common'
import { PrismaService } from '../prisma/prisma.service'
import { AuthDto } from './dto'
import { createUser } from './functions/CreateUser'
import { JwtService } from '@nestjs/jwt'
import { signToken } from './functions/CreateSiginToken'
import { ConfigService } from '@nestjs/config'
import { findUser } from './functions/FindUser'

@Injectable({})
export class AuthService {
  constructor(
    private config: ConfigService,
    private prisma: PrismaService,
    private jwt: JwtService,
  ) {}
  sigup(dto: AuthDto) {
    return createUser(dto, this.prisma)
  }

  async sigin(dto: AuthDto) {
    const user = await findUser(dto, this.prisma)
    return signToken(
      this.jwt,
      user.id,
      user.email,
      this.config.get('SECRET-JWT'),
    )
  }
}
