import { Injectable } from '@angular/core';
import * as moment from "moment";

@Injectable()
export class AuthService {

    constructor() {}
          
    setLocalStorage(responseObj) {
        const expires = moment().add(responseObj.expires);

        localStorage.setItem('token', responseObj.token);
        localStorage.setItem('expires', JSON.stringify(expires.valueOf()));

    }          

    logout() {
        localStorage.removeItem('token');
        localStorage.removeItem('expires');
    }

    isLoggedIn() {
        return moment().isBefore(this.getExpiration())
    }

    isLoggedOut() {
        return !this.isLoggedIn()
    }

    getExpiration() {
        const expiration = localStorage.getItem("expires");
        const expiresAt = JSON.parse(expiration);
        return moment(expiresAt)
    }    
}