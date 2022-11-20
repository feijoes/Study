import { View, Text, StyleSheet, TouchableNativeFeedback } from "react-native";
import React from "react";
import Icon from "react-native-vector-icons/MaterialCommunityIcons";
//
const Home = ({ setIsUserLogin }) => {
  const Logout = () => {
    console.log(3)
  };

  return (
    <View style={styles.container}>
      <Text>Home</Text>
      <View style={styles.logoutContainer}>
        <TouchableNativeFeedback onPress={Logout}>
          <Icon.Button
            name="logout"
            size={30}
            backgroundColor="#fff"
            iconStyle={{ color: "black" }}
          />
        </TouchableNativeFeedback>
      </View>
    </View>
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
