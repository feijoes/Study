

module.exports.isAuth = (req, res, next) =>{
    if (req.isAuthenticated()){
        next()
    } else{
        res.status(401).json({msg:"you are not login"})
    }
}

module.exports.isAdmin = (req, res, next) =>{
    if (req){
        next()
    } else{
        res.status(401).json({msg:"you are not login"})
    }
}