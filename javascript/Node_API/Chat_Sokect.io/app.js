const express = require('express');
const app = express();
const SokectIO = require("socket.io");
const path = require('path')


app.use(express.static(path.join(__dirname, 'public')));

const io = SokectIO(app.listen(3000))

// websockets
io.on('connection',(connection)=>{
    connection.on('message',(data)=>{
        io.sockets.emit('servermessage',data)
    })
    connection.on('typing',(data)=>{
        connection.broadcast.emit('typing',data)
    })
})


