import { Controller, Get, UseGuards, Patch } from '@nestjs/common'
import { User } from '@prisma/client'
import { GetUser } from '../auth/decorator'
import { JwtGuard } from '../auth/guard'

@UseGuards(JwtGuard)
@Controller('user')
export class UserController {
  @Get('me')
  getUserData(@GetUser() user: User) {
    return user
  }

  @Patch()
  editUser(@GetUser() user: User) {
    return ' '
  }
}
