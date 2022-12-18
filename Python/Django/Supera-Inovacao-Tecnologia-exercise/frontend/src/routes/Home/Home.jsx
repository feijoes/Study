import { useState } from 'react'
import { Link } from 'react-router-dom'

function Home() {
  

  return (
    <div >
        Home page
        
        <Link className='link' to='auth'><h3>Sign In</h3></Link>
    </div>
  )
}

export default Home
