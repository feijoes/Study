import { BrowserRouter, Routes, Route } from "react-router-dom";
import Home from "./layout/Home/Home";
import Header from "./components/Header/Header";
function App() {
  return (
    <>
      <Header />
      <BrowserRouter>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="contact" element={<h2>HI@</h2>} />
          <Route path="*" element={<h4>ddd</h4>} />
        </Routes>
      </BrowserRouter>
    </>
  );
}

export default App;
