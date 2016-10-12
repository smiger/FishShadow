varying vec2 v_texCoord;

void main(){
float shadowMask = texture2D(CC_Texture0, v_texCoord).a;
const float shadowOpacity = 0.5;
gl_FragColor = vec4(0,0,0,shadowMask *shadowOpacity);
}