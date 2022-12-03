import * as React from "react";
import SeePostScreen from "./SeePostScreen";
import CreatePost from "./CreatePost";
import Ionicons from "react-native-vector-icons/Ionicons";
import { NavigationContainer } from "@react-navigation/native";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";
import { Logout } from "../components";
const Tab = createBottomTabNavigator();
const homeName = "Posts";
const detailsName = "Create Post";

const ScreensContainer = ({ setIsUserLogin }) => {
  return (
    <>
      <NavigationContainer>
        <Logout setIsUserLogin={setIsUserLogin} />
        <Tab.Navigator
          initialRouteName={homeName}
          screenOptions={({ route }) => ({
            tabBarIcon: ({ focused, color, size }) => {
              let iconName;
              let rn = route.name;

              if (rn === homeName) {
                iconName = focused ? "home" : "home-outline";
              } else if (rn === detailsName) {
                iconName = focused ? "create" : "create-outline";
              }

              // You can return any component that you like here!
              return <Ionicons name={iconName} size={size} color={color} />;
            },
            tabBarActiveTintColor: "tomato",
            tabBarInactiveTintColor: "grey",
            tabBarLabelStyle: {
              paddingBottom: 10,
              fontSize: 12,
            },
            tabBarStyle: [
              {
                display: "flex",
              },
              null,
            ],
          })}
        >
          <Tab.Screen name={homeName} component={SeePostScreen} />
          <Tab.Screen name={detailsName} component={CreatePost} />
        </Tab.Navigator>
      </NavigationContainer>
    </>
  );
};

export default ScreensContainer;
