import { JwtService } from '@nestjs/jwt'

export const signToken = async (
  jwt: JwtService,
  userId: number,
  email: String,
  secret: any,
): Promise<{ access_token: string }> => {
  const payload = {
    sub: userId,
    email,
  }
  const token = await jwt.signAsync(payload, {
    expiresIn: '60m',
    secret: secret,
  })
  return {
    access_token: token
  }
}
