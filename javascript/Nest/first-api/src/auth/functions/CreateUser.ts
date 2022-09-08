import { ForbiddenException } from '@nestjs/common'
import { PrismaClientKnownRequestError } from '@prisma/client/runtime'
import * as argon from 'argon2'
import { throwError } from 'rxjs'
import { PrismaService } from 'src/prisma/prisma.service'
import { AuthDto } from '../dto'

export const createUser = async (dto: AuthDto, prisma: PrismaService) => {
  const hash = await argon.hash(dto.password.toString())
  try {
    const user = await prisma.user.create({
      data: {
        email: dto.email.toString(),
        hash,
      },
      select: {
        id: true,
        email: true,
        createAt: true,
      },
    })
    return user
  } catch (error) {
    if (error instanceof PrismaClientKnownRequestError) {
      if (error.code == 'P2002')
        throw new ForbiddenException('Credentias taken')
    }
  }
}
