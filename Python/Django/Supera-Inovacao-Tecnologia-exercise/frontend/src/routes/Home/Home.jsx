import { useRef, useState, useEffect, useContext } from "react";
import { AuthContext } from "../../context";
import { Link } from "react-router-dom";
import axios from "axios";
import { Produto } from "../../components/";
import styles from "./Home.module.css";

function Home() {
  const { cookies, API_URL } = useContext(AuthContext);
  const [produtos, setProdutos] = useState([]);
  
  useEffect(() => {
    const getProdutos = async () => {
      const request = await axios.get(API_URL + "produtos/");
      setProdutos(request.data);
    };
    getProdutos();
  }, []);

  return (
    <div className={styles.container}>
          <ul className={styles.productList}>
            {produtos &&
              produtos.map((produto) => {
                return <Produto key={produto.name} produto={produto} />;
              })}
          </ul>
    </div>
  );
}

export default Home;
