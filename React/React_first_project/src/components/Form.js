import React, { Component } from 'react'
import './CSS/style.css'


class Form extends Component {
    constructor(props) {
        super(props)

        this.state = {
            Nombre: "",
            Apellido: "",
            Email: "",
            Telefono: "",
            Contraseña: "",
            ConfirmContraseña: "",


        }
        this.handleSubmit=this.handleSubmit.bind(this)
    }

    Nombre = (event) => {
        this.setState({
            Nombre: event.target.value
        })
    }
    Apellido = (event) => {
        this.setState({
            Apellido: event.target.value
        })
    }
    Email = (event) => {
        this.setState({
            Email: event.target.value
        })
    }

    Telefono = (event) => {
        this.setState({
            Telefono: event.target.value
        })
    }
    Contraseña = (event) => {
        this.setState({
            Contraseña: event.target.value
        })
    }
    ConfirmarContraseña = (event) => {
        this.setState({
            ConfirmarContraseña: event.target.value
        })
    }

    handleSubmit = (event) => {
        alert(`${this.state.Nombre} ${this.state.Apellido}  Registered Successfully !!!!`)
        console.log(this.state);
        this.setState({
            Nombre: "",
            Apellido: "",
            Email: "",
            Telefono: "",
            Contraseña: "",
            ConfirmarContraseña: "",
        })
     event.preventDefault()
        
    }




    render() {
        return (
            <div>
                <form onSubmit={this.handleSubmit}>
                    <h1>Registro</h1>
                    <label>Nombre :</label> <input type="text" value={this.state.Nombre} onChange={this.Nombre} placeholder="Nombre..." /><br />
                    <label>Apellido:</label> <input type="text" value={this.state.Apellido} onChange={this.Apellido} placeholder="Apellido..." /><br />
                    <label>Email :</label> <input type="text" value={this.state.Email} onChange={this.Email} placeholder="Email..." /><br />
                    <label>Telefono :</label> <input type="text" value={this.state.Telefono} onChange={this.Telefono} placeholder="Telefono..." /><br />
                    <label>Contraseña :</label> <input type="password" value={this.state.Contraseña} onChange={this.Contraseña} placeholder="Contraseña..." /><br />
                    <label>Confirmar Contraseña:</label> <input type="password" value={this.state.ConfirmarContraseña} onChange={this.ConfirmarContraseña} placeholder="Confirmar Contraseña..." /><br />
                    <input type="submit" value="Subir" />
                </form>
            </div>
            
        )
    }
}

export default Form


