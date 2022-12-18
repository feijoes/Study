import { createContext, useState } from "react";
import Cookies from 'universal-cookie';
export const AuthContext = createContext({});
export const AuthProvider = ({ children }) => {
  const [auth, setAuth] = useState({});
  const LOGIN_URL= 'http://127.0.0.1:8000/'
  const cookies = new Cookies();
  const [isLogin,setIsLogin] = useState(cookies.get("accessToken") != null) 
   
  return (
    <AuthContext.Provider value={{ auth, setAuth, LOGIN_URL,cookies ,isLogin}}>
      {children}
    </AuthContext.Provider>
  );
};


