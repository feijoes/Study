import { Injectable } from '@nestjs/common';

@Injectable({})
export class AuthService {
  sigup() {
    return { msg: 'You have signed up' };
  }

  sigin() {
    return { msg: 'You have signed in' };
  }
}
