#version 460
out vec4 fragment;
void main() {
    vec2 p = (gl_FragCoord.xy * 2.0 - 500) / min(500, 500);
    float l = 0.1 / length(p);
    fragment = vec4(vec3(l), 1.0);
}
