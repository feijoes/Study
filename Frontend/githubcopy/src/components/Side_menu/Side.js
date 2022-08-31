import React from "react";
import side from "./Side.module.css";
import SVG from "../SimpleComponents/SVG";
const Side = () => {
  return (
    <aside className={side.sidecontainer}>
      <div className={side.sidebar}>
        <h2 className={side.up}>
        
          Recent Repositories
          <a className={side.newrepo} href="/#">
            <SVG type={'Repository'} />
            New
          </a>
        </h2>
        
        <input
          type="text"
          placeholder="Find a repository..."
          autoCapitalize="off"
          aria-controls="jump-to-results"
          aria-label="Find a repository..."
          style={{width:'75%'}}
        />
        
      
      </div>
    </aside>
  );
};

export default Side;
