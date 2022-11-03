import { StyleSheet, ImageBackground, View, Image, Text } from "react-native";
import React from "react";

export default function WelcomeScreens() {
  return (
    <ImageBackground
      style={styles.background}
      source={require("../assets/backgorund.jpg")}
    >
      <View style={styles.logoView}>
        <Image
          style={styles.logo}
          source={require("../assets/logo-red.png")}
        ></Image>
        <Text> Sell What You Don't Need </Text>
      </View>
      <View style={styles.loginButton}></View>
      <View style={styles.registerButton}></View>
    </ImageBackground>
  );
}

const styles = StyleSheet.create({
  background: {
    flex: 1,
    justifyContent: "flex-end",
    alignItems: "center",
  },
  loginButton: {
    width: "100%",
    height: 70,
    backgroundColor: "#fc5c65",
  },
  registerButton: {
    width: "100%",
    height: 70,
    backgroundColor: "#4ecdc4",
  },
  logo: {
    width: 100,
    height: 100,
  },
  logoView: {
    position: "absolute",
    top: 70,
    alignItems :"center",
  }
});
