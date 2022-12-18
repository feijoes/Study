import { useState } from 'react'
import Home from './routes/Home/Home'
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
function App() {
  

  return (
    <div className='app'>
    <Router>
      <Routes>
        <Route path="/" element={<Home />} />
      </Routes>
    </Router>
   </div>
  )
}

export default App
