import { createContext } from "react";

export const AppContext = createContext();
export function APP({ children }) {

  
    
  return <AppContext.Provider value={{

  }}>{children}</AppContext.Provider>;
}
