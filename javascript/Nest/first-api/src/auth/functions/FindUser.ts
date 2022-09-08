import { AuthDto } from '../dto'
import { PrismaService } from 'src/prisma/prisma.service'
import { ForbiddenException } from '@nestjs/common'
import * as argon from 'argon2'

export const findUser = async (dto: AuthDto, prisma: PrismaService) => {
  const user = await prisma.user.findUnique({
    where: {
      email: dto.email.toString(),
    },
  })

  if (!user) throw new ForbiddenException('Credentials incorrect')

  const pwMatches = await argon.verify(user.hash, dto.password.toString())
  if (!pwMatches) throw new ForbiddenException('Credentials incorrect')

  delete user.hash

  return user
}
