import { Component,OnInit } from "@angular/core";
import {FormGroup,FormBuilder,Validators} from "@angular/forms"
import { matchingPassword } from "./validators";
@Component({
  selector: "app-register",
  templateUrl: "./register.component.html",
  styleUrls: ["./register.component.css"]
})
export class RegisterComponent implements OnInit{
  addForm: FormGroup;
  constructor(private fb: FormBuilder) {
    
  }
  ngOnInit():void{
    this.addForm = this.fb.group({
      email : ["",Validators.required],
      password : ["",Validators.required],
      password2 : ["",Validators.required]
    },{validator: matchingPassword("password","password2")});
  };

  addUser(): void {
    console.log(this.addForm)
    if (this.addForm.valid){
      var addUser = {
        email: this.addForm.controls["email"].value,
        password: this.addForm.controls["password"].value
      };
      console.log(addUser);
      this.addForm.reset()
    };
  };
};