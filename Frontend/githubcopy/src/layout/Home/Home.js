import React from "react";
import Side from "../../components/Side_menu/Side";
import style from "./Home.module.css";
import Feed from "../../components/Feed/Feed";
const Home = () => {
  return (
    <div className={style.homeContainer}>
      <Side />
      <div className={style.container}>
        <Feed />
        
      </div>
    </div>
  );
};

export default Home;
