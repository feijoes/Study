import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import Home from "./layout/Home/Home";
import Header from "./components/Header/Header";
import { APP } from "./context/MainContext";
function App() {
  return (
    <>
      <Router>
        <APP>
          
          <Header />
          <Routes>
            <Route exact path="/" element={<Home />} />
            <Route path="contact" element={<h2>HI@</h2>} />
            <Route path="*" element={<h4>ddd</h4>} />
          </Routes>
        </APP>

      </Router>
    </>
  );
}

export default App;
