import { useState } from 'react'
import {Home,Auth} from './routes/'
import { BrowserRouter as Router, Routes, Route, } from "react-router-dom";

function App() {
  

  return (
    <div className='app'>
    <Router>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/auth" element={<Auth />} />
      </Routes>
    </Router>
   </div>
  )
}

export default App
