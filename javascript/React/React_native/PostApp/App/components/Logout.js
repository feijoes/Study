import {
    View,
    StyleSheet,
    TouchableNativeFeedback,
    Alert,
  } from "react-native";
import React from 'react'
import Icon from "react-native-vector-icons/MaterialCommunityIcons";
import AsyncStorage from "@react-native-async-storage/async-storage";


export default function Logout({setIsUserLogin}) {
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
  )
}

const styles = StyleSheet.create({
    logoutText: {
      color: "black",
    },
    logoutContainer : {
      position: "absolute",
      left: "85%",
      top: "4%",
      zIndex: 3,
      
    }
  });
  