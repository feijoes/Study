import * as argon from 'argon2'
import { PrismaService } from 'src/prisma/prisma.service'
import { AuthDto } from '../dto'

export const createUser = async (dto: AuthDto,prisma:PrismaService) =>{
    const hash =  await argon.hash(dto.password.toString())   
    const user = await prisma.user.create({
        data:{
            email: dto.email.toString(),
            hash,
        },
        select:{
            id: true,
            email: true,
            createAt : true,
        }
    })
    
    return user 
}
