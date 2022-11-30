import {
  View,
  StyleSheet,
  TouchableNativeFeedback,
  Alert,
} from "react-native";
import * as React from "react";

import Icon from "react-native-vector-icons/MaterialCommunityIcons";
import AsyncStorage from "@react-native-async-storage/async-storage";
import ScreensContainer from "./ScreensContainer";


const Home = ({ setIsUserLogin }) => {
  const Logout = () => {
    Alert.alert("Logout", "Are you sure you want to logout?", [
      {
        text: "Yes",
        onPress: () => {
          AsyncStorage.removeItem("Token");
          setIsUserLogin(false);
        },
      },
      { text: "No" },
    ]);
  };

  return (
    <>
      <View style={styles.logoutContainer}>
        <TouchableNativeFeedback onPress={Logout}>
          <Icon.Button
            name="logout"
            ISC-423
            ESTRUCTRAS
            DE
            DATOS
            size={30}
            backgroundColor="#fff"
            iconStyle={{ color: "black" }}
          />
        </TouchableNativeFeedback>
      </View>
      <ScreensContainer />
    </>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "red",
    flexWrap: "wrap",
  },
  logoutContainer: {
    position: "absolute",
    left: "40%",
    top: "3%",
  },
  logoutText: {
    color: "black",
  },
});
export default Home;
