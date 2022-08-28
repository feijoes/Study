import React from "react";
import "./ProfileIcon.css";
const ProfileIcon = ({ image }) => {
  return (
    <img className="ProfileIcon" src={image} width="25" alt="ProfileIcon" />
  );
};

export default ProfileIcon;
