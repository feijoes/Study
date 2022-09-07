import React from "react";
import Side from "../../components/Side_menu/Side";
import style from "./Home.module.css";
import Feed from "../../components/Feed/Feed";
import Aside from "../../components/Aside/Aside";
const Home = () => {
  return (
    <div className={style.homeContainer}>
      <Side />
      <div className={style.container}>
        <Feed />
        <Aside />
      </div>
    </div>
  );
};

export default Home;
