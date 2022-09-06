import { Body, Controller, Post } from '@nestjs/common'
import { AuthService } from './auth.service'
import { AuthDto } from './dto'

@Controller('auth')
export class AuthController {
  constructor(private authService: AuthService) {}
  @Post('signup')
  signup(@Body('email') email: String, @Body('password') password: String) {
    return this.authService.sigup()
  }
  @Post('sigin')
  sigin() {
    return this.authService.sigin()
  }
}
