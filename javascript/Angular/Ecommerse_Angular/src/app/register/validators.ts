import {FormGroup} from '@angular/forms'; 
type Falsy = null | undefined | false | 0 | '' | any;
export function matchingPassword(passwordKey: string, confirmPasswordKey: string){
    return (group: FormGroup):{
        [key:string]:Falsy
    } =>{
        let password = group.controls[passwordKey];
        let confirmPassword = group.controls[confirmPasswordKey];
        
        if (password.value !== confirmPassword.value){
            return {
                matchingPasswords :true
            };
        }
    };
};