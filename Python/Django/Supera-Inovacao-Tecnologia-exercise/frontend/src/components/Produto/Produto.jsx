import { useRef, useState, useEffect, useContext } from "react";
import { AuthContext } from "../../context";
import styles from "./Produto.module.css"
export const Produto = ({ produto }) => {
  const { API_URL } = useContext(AuthContext);
  return (
    <>
      <li>
        <div className={styles.product}>
          <div className={styles.productImage}>
            <img src={API_URL +"static/"+produto.image} />
          </div>
          <div className={styles.productImformation}>
            <h4>{produto.name}</h4>
            <div className={styles.specification}>
              <span>{produto.score} </span>
            </div>
            <span>${produto.price}</span>
          </div>
        </div>
        <button onClick={}>Comprar</button>
      </li>
    </>
  );
};
