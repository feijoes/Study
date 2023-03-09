import { serve } from "https://deno.land/std@0.156.0/http/server.ts";
import { handler } from "../build/feijoes.js";

serve(handler);
