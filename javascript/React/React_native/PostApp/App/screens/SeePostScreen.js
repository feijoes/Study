import { StyleSheet, ScrollView, View } from "react-native";
import React from "react";
import PostsTest from "../TestJson/PostsTest";
import { Post } from "../components/";
import axios from "axios";
import AsyncStorage from "@react-native-async-storage/async-storage";

const API_URL =
  Platform.OS === "ios" ? "http://localhost:5000/" : "http://10.0.2.2:5000/";

const SeePostScreen = () => {
  const [posts, setPosts] = React.useState([]);
  React.useEffect(() => {
    async function get() {
      let userToken;
      try {
        userToken = await AsyncStorage.getItem("Token");
      } catch (e) {
        console.log(e);
      }
      axios
        .get(`${API_URL}routes/posts/`, {
          headers: {
            authorization: userToken,
          },
        })
        .then((request) => {
          setPosts(request.data.posts)
        })
        .catch((error) => {
          console.log(error);
        });
    }
    get();
  }, []);
  return (
    <View style={styles.container}>
      <ScrollView style={{ bounces: false }}>
        <View>
          {posts.map((POST) => (
            <Post POST={POST} key={POST.Id} />
          ))}
        </View>
      </ScrollView>
    </View>
  );
};

export default SeePostScreen;

const styles = StyleSheet.create({
  container: {
    width: 400,
    padding: 30,
    marginTop: 20,
    paddingTop: 30,
    marginLeft: -5,
  },
});
