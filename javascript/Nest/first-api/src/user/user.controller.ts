import { Controller, Get, UseGuards, Req } from '@nestjs/common'
import { JwtGuard } from 'src/auth/guard'

@Controller('user')
export class UserController {
  @UseGuards(JwtGuard)
  @Get('me')
  getUserData(@Req() req) {
    console.log()
    return 'user info'
  }
}
