const mongoose = require("mongoose");

require("dotenv").config();

const devConnection = process.env.DB_STRING;
const prodConnection = process.env.DB_STRING_PROD;
try {
  if (process.env.NODE_ENV === "production") {
    mongoose.connect(prodConnection, {
      useNewUrlParser: true,
      useUnifiedTopology: true,
    });

    mongoose.connection.on("connected", () => {
      console.log("Database connected");
    });
  } else {
    mongoose.connect(devConnection, {
      useNewUrlParser: true,
      useUnifiedTopology: true,
    });

    mongoose.connection.on("connected", () => {
      console.log("Database connected");
    });
  }
} catch (Error) {
  console.log("Error in connecting to dabase");
}
