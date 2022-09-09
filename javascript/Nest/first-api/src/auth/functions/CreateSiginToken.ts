import { JwtService } from '@nestjs/jwt'

export const signToken = async (
  jwt: JwtService,
  userId: number,
  email: String,
  secret: any,
): Promise<string> => {
  const payload = {
    sub: userId,
    email,
  }
  return jwt.signAsync(payload, {
    expiresIn: '60m',
    secret: secret,
  })
}
