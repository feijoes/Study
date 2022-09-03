const socket = io()

let message = document.getElementById("message")
let btn = document.getElementById("send")
let username = document.getElementById("username")
let actions = document.getElementById("actions")
let output = document.getElementById("output")

btn.addEventListener('click',()=>{
    socket.emit("message",{
        message: message.value,
        username: username.value

    })
    message.value = ''; 
})
message.addEventListener('keypress',()=>{
    socket.emit('typing',username.value)
})
socket.on('servermessage',(data)=>{
    output.innerHTML += `<p>
    <strong>${data.username}</strong>:${data.message}
    </p>`
})
socket.on('typing',(data)=>{
    console.log(data)
    actions.innerHTML = `<p>${data}</p>`
})