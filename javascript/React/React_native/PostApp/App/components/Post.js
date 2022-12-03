import { View, Text, StyleSheet } from "react-native";
import React from "react";
import AsyncStorage from "@react-native-async-storage/async-storage";

const Post = ({ POST }) => {
  const [user, setUser] = React.useState({});
  React.useEffect(() => {
    const get = async () => {
      let User;
      try {
        User = await AsyncStorage.getItem("User");

        setUser(User);
      } catch (e) {
        console.log(e);
      }
    };

    get();
  }, []);

  const isUser = POST.user === user;
 
  return (

    <>
      <View
        style={[
          styles.message,
          isUser ? styles.messageUser : styles.messageOther,
        ]}
      >
        <Text style={styles.messageContent}>{POST.body}</Text>
        <View style={[styles.messageTime, isUser ? { right: 5 } : { left: 6 }]}>
          <Text style={{ fontSize: 9.5, fontWeight: "330",marginBottom: 3 }}>{POST.time.slice(0,10)}</Text>
        </View>
        <View style={[styles.messageTime, !isUser ? { right: 5 } : { left: 5 }]}>
          <Text style={{ fontSize: 12, fontWeight: "400", marginRight: 4,marginBottom: 3 }}>
            {POST.user}
          </Text>
        </View>
      </View>
    </>
  );
};

const styles = StyleSheet.create({
  message: {
    position: "relative",
    marginBottom: 10,
    padding: 10,
    maxWidth: "60%",
    minHeight: 50,
    borderRadius: 10,
    textAlign: "left",
    borderWidth: 1,
    overflow: "visible",
  },
  messageOther: {
    marginLeft: 20,
    backgroundColor: "#f8e896",
    borderColor: "#dfd087",
  },
  messageUser: {
    marginLeft: "40%",
    backgroundColor: "#A8DDFD",
    borderColor: "#A8DDFD",
  },
  messageContent: {
    padding: 0,
    margin: 0,
    marginBottom: 15,
  },
  messageTime: {
    position: "absolute",
    bottom: -1,
    overflow: "visible",
    display: "flex",
    flexDirection: "row",
  },
});

export default Post;
